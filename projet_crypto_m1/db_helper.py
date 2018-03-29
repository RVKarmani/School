# db_helper.py
import sys
import hashlib
from sqlalchemy import create_engine

class User:
    def __init__(self, id, login, password, phone):
        self.id = id
        self.login = login
        self.password = password
        self.phone = phone

class Users:
    def __init__(self, db_file):
        # try import db
        try:
            self.db = create_engine('sqlite:///' + db_file)
        except:
            print "[*] Error Loading/Creating " + db_file
            sys.exit(0)

        # set up the rest
        self.conn = self.db.connect()

    def AttemptLogin(self, login, password):
        # hash password and compare
        hashpwd = hashlib.sha256(password).hexdigest()
        query = self.conn.execute("select id from users where login='%s' and password='%s'" % (login, hashpwd))
        data = query.fetchall()
        
        if(len(data)>0):
            return data[0][0]
        else:
            return 0

    def AddUser(self, new_login, new_password, new_phone):
        hashpwd = hashlib.sha256(new_password).hexdigest()
        query = self.conn.execute("insert into users(login, password, phone) values ('%s', '%s', '%s')" % (new_login, hashpwd, new_phone))

    def GetRecordFromID(self, id):
        query = self.conn.execute("select * from users where id=%i" % id)
        data = [dict(zip(tuple (query.keys()) ,i)) for i in query.cursor][0]
        return User(data["id"],data["login"],data["password"],data["phone"])