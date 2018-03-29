# twilio_helper.py
from twilio.rest import Client

class TwilioSMSHelper:
    def __init__(self, sid, at, twpn):
        self.account_sid = sid
        self.auth_token = at
        self.client = Client(sid, at)
        self.twiliophonenumber = twpn

    def SendSms(self, dest, msg):
        try:
            message = self.client.api.account.messages.create(to=dest, from_=self.twiliophonenumber, body=msg)
            return True
        except:
            return False