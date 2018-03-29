# import
import argparse
import sys
import signal

# custom libs
from cbc import CBC
from twilio_helper import TwilioSMSHelper
from otp import TOTP
from db_helper import Users, User

# set encoding appropriatly
reload(sys)
sys.setdefaultencoding('iso-8859-1')

#Twilio SMS Service Settings
twilio_sid = "ACf4b4128be9f4c0f87625e19d8fdba01d"
twilio_auth_token = "a7a094198d9f8c435a7f3401631bb177"
twilio_registred_phone = "+17868286818"

#define database files
db_users_file = "users.db"

def PerformNewEntry(db_conn):
    print "[*] Add a new user to db!"
    login = raw_input("[*] Login: ")
    pwd = raw_input("[*] Password: ")
    phone = raw_input("[*] Phone number (+33): ")
    
    db_conn.AddUser(login, pwd, phone)
    print "[*] Done!"


def PerformLogin(db_conn):
    print "[*] Please login!"

    id = 0
    while id == 0:
        login = raw_input("[*] Login: ")
        pwd = raw_input("[*] Password: ")
        id = db_conn.AttemptLogin(login, pwd)
        if id != 0:
            break
        else:
            print "[*] Wrong Password!"

    return id

def HandleTOTP(sms_handler, user_obj):
    otp = TOTP("secret", digits=6)
    clock0_totp = "123456"
    clock1_totp = "654321"

    while True:
        if clock0_totp != clock1_totp:
            
            clock0_totp = otp.genOTP()
            
            if sms_handler.SendSms("+33646269585", "Your OTP password is: " + clock0_totp):
                print "[*] OTP Challenge has been sended by sms to: " + user_obj.phone
            else:
                print "[*] Sms provider error!"
                print "[*] Exiting..."
                sys.exit(0)
        

        resolve = raw_input("[*] Enter TOTP Challenge Code: ")
        otp.UpdateClock()
        clock1_totp = otp.genOTP()

        if clock1_totp == resolve:
            break

        print "[*] Wrong TOTP"

    return True

def PerformDecryptAction():
    #Here we call the decrypt function
    print "[*] Decryption Mode, you may decrypt anyfile you want..."
    
    while True:
        infile = raw_input("[*] Input File: ")
        output = raw_input("[*] Output File: ")
        passphrase = raw_input("[*] PassPhrase: ")

        cbc = CBC(file_in=infile, file_out=output, key=passphrase)

        cbc.decrypt()

def PerformEncryptAction():
    #Here we call the crypt function
    print "[*] Decryption Mode, you may decrypt anyfile you want..."
    
    while True:
        infile = raw_input("[*] Input File: ")
        output = raw_input("[*] Output File: ")
        passphrase = raw_input("[*] PassPhrase: ")

        cbc = CBC(file_in=infile, file_out=output, key=passphrase)

        cbc.encrypt()

def get_args():
    parser = argparse.ArgumentParser(
        description='ESGI CryptoProjet Tool Version 1 - SUEUR Tanguy/Anthony Vernhet')
    # Add arguments
    parser.add_argument(
        '-a', '--adduser', type=str, help='Add a new user')
    parser.add_argument(
        '-c', '--encrypt', type=str, help='Encryption mode')
    parser.add_argument(
        '-d', '--decrypt', type=str, help='Decryption mode')
    # Array for all arguments passed to script
    args = parser.parse_args()

    if not (args.adduser or args.encrypt or args.decrypt):
        parser.print_help()
        sys.exit(0)

    return args

def signal_handler(signal, frame):
        print "[*] Signal handler will quit!"
        sys.exit(0)

def main():
    signal.signal(signal.SIGINT, signal_handler)

    args = get_args()

    db_users_conn = Users(db_users_file)
    sms_provider = TwilioSMSHelper(twilio_sid, twilio_auth_token, twilio_registred_phone)

    if args.adduser is not None:
        PerformNewEntry(db_users_conn)

    id = PerformLogin(db_users_conn)

    user = db_users_conn.GetRecordFromID(id)

    if HandleTOTP(sms_provider, user):
        print "[*] Welcome " + user.login

    if args.decrypt is not None:
        PerformDecryptAction()

    if args.encrypt is not None:
        PerformDecryptAction()
    

if __name__ == "__main__":
    main()