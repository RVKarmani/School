# otp.py
import time
import hashlib
import struct
import hmac

class TOTP:
    # RFC6238 mentions SHA-256 and SHA-512
    def __init__(self, secret, clock=None, module=hashlib.sha512, digits=4, time_window=60):
        self.digestmod = module
        self.window = time_window
        self.K = secret
        self.digits = digits
        self.clock = clock

    def UpdateClock(self):
        self.clock = time.time()

    def genOTP(self):

        #get clock for derivating counter HOTP
        if self.clock is None:
            self.clock = time.time()

        timer = int(self.clock / self.window)

        timer_bytes = struct.pack(b"!Q", timer)

        #generating TOTP
        hmac_digest = hmac.new(key=self.K, msg=timer_bytes, digestmod=self.digestmod).hexdigest()
        
        #http://tools.ietf.org/html/rfc4226#section-5.3
        offset = int(hmac_digest[-1], 16)
        binary = int(hmac_digest[(offset * 2):((offset * 2) + 8)], 16) & 0x7fffffff
        return str(binary)[-self.digits:]