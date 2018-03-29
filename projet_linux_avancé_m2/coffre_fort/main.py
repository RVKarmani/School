#! /usr/bin/env python
#coding: utf-8


from flask import Flask, render_template, request, redirect, url_for, jsonify, session
import socket, re, os, sys, hashlib, jinja2
from sqlalchemy import create_engine
from werkzeug.utils import secure_filename
from os import listdir
from os.path import isfile, join
import gnupg


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
            self.db = create_engine('sqlite:///{0}'.format(db_file))
        except:
            print("[*] Error Loading/Creating {0}".format(db_file))
            sys.exit(0)

        # set up the rest
        self.conn = self.db.connect()

    def AttemptLogin(self, login, password):
        # hash password and compare
        hashpwd = hashlib.sha256(password.encode('utf-8')).hexdigest()
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

#DEFINE APP
UPLOAD_FOLDER = '/home/loktis/Documents/github/gpgPr/venvgpgPr/static/testfilesfolder/'
ALLOWED_EXTENSIONS = set(['txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'])
app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER 

def get_files():
    a="OK"
    return a  


def PerformLogin(db_conn):
    id = 0
    login = request.form['username']
    pwd = request.form['password']
    id = db_conn.AttemptLogin(login, pwd)
    if id != 0:
        return True
    else:
        print("[*] Wrong Password!")
        return False 

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


@app.route('/', methods=['GET', 'POST'])
def login():
    error=None
    #DEFINE DATABASE
    db_users_file = "/home/loktis/Documents/github/gpgPr/venvgpgPr/static/users.db"
    db_users_conn = Users(db_users_file)
    if request.method == 'POST':
        if PerformLogin(db_users_conn)==False: 
            error = 'Invalid Credentials. Please try again.'
        else:
            session['logged_in'] = True
            return redirect(url_for('coffre_fort'))

    if request.method == 'GET' and session.get('logged_in'):
        return redirect(url_for('coffre_fort'))
    return render_template('login.html', error=error)


@app.route('/logout')
def logout():
    session['logged_in'] = False
    return login()

@app.route('/coffre' )
def coffre_fort():
    if not session.get('logged_in'):
        return login()
    else:
        return render_template('coffre_fort.html',a=get_files())

@app.route('/contact')
def contact():
    if not session.get('logged_in'):
        return login()
    else:
        return render_template('contact.html')

@app.route('/getter', methods=['POST'])
def getter_files():
    if not session.get('logged_in'):
        return login()
    else:
        if request.method == 'POST':
            text = request.form['text']
            passphrase = request.form['password']
            print(text)
            print(passphrase)
    return render_template('coffre_fort.html')

@app.route('/404')
def connection_error():
    return render_template('404.html')

@app.route('/uploader', methods = ['GET','POST'])
def uploader_files():
    if not session.get('logged_in'):
        return login()
    else:
        if request.method == 'POST':
        # check if the post request has the file part
            if 'file' not in request.files:
                print('No file part')
                return redirect(request.url)
            f = request.files['file']
            # if user does not select file, browser also
            # submit a empty part without filename
            if f.filename == '':
                print('No selected file')
                return redirect(request.url)
            if f and allowed_file(f.filename):
                filename = secure_filename(f.filename)
                f.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
                gpg = gnupg.GPG(homedir='/home/loktis/Documents/github/gpgPr/venvgpgPr/static/testfilesfolder/testfilesfoldergpg')
                gpg.encrypt(filename,'5FC424D915CA992301D5069B5BD403A48601B990',output='/home/loktis/Documents/github/gpgPr/venvgpgPr/static/testfilesfolder/testfilesfoldergpg/filesenc/'+filename+".gpg")

    return redirect(url_for('coffre_fort'))

if __name__ == '__main__':

    ALLOWED_EXTENSIONS = set(['txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'])
    app.secret_key = os.urandom(254)
    app.run(host='127.0.0.1', port=8080, debug=True)
