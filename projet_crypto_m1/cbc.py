# cbc.py
# -*- coding: utf-8 -*-

# Modules import
import os
import hashlib

from itertools import izip, cycle

class CBC:
    def __init__(self, file_in, key, file_out='/tmp/bufcbc.txt', block_size=256, iV=None):
        # Size of each block
        self.block_size_bits = block_size
        
        # min block size is 8 bits
        if self.block_size_bits < 8:
            self.block_size_bits = 8

        # size block in bytes
        self.block_size_bytes = self.block_size_bits/8
        
        # setting custom iv
        self.IV = iV

        # Initialisation vector generation
        if self.IV is None:
            self.IV = self.genIV()

        # set enc/dec key passphrase
        self.key = key

        # set file params
        self.file_in = file_in
        self.file_out = file_out

    # Initialisation vector generation function
    def genIV(self):
        return os.urandom(self.block_size_bytes)

    # Padding generation function
    def padding(self, size):
        return chr(0xFF) * size

    # Key hash generation function
    def hashing_key(self, tohash):
        return hashlib.sha256(tohash).digest()

    # Xor function
    def xor_crypt(self, data, key):
        # Foreach carac x and y respectively present in data and key xor x from data with y from key
        xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(data, cycle(key)))
        # Return xored value
        return xored

    # Decrypt CBC function
    def decrypt(self):
        #generate 256bit key (sha256bits)
        key = self.hashing_key(self.key)
        # Init the blocks counter
        iteration = 0 
        # Open input and output streams
        # Input file is open as buffer_in with read permission
        with open(self.file_in, "rb") as buffer_in:
            # The last block is our initialisation vector
            last_block = buffer_in.read(self.block_size_bytes)
            # Displaying initialisation vector
            print('IV : 0x' + last_block.encode('hex'))
            # Open output file as buffer_out with write permission
            with open(self.file_out, 'wb') as buffer_out:
                # Loop while there is content
                while True:
                    # We get the current block and decoding it
                    curr_block = buffer_in.read(self.block_size_bytes).decode()
                    # If the block is not empty
                    if curr_block != '':
                        # Then we decrypt it with the key and after we xor it with the initialisation vector
                        dexor = self.xor_crypt(self.xor_crypt(curr_block,key),last_block)
                        # Encoding in utf-8
                        dexorUtf = dexor.encode()
                        # Display the number of the block and the decrypt content
                        print('=============================================================')
                        print('# Decipher Block N°' + str(iteration) + ' with hashed key 0x' + key.encode('hex'))
                        print('# Decipher Block : ' + dexorUtf)
                        print('=============================================================')
                        # Then the last_block var takes the value of the current block
                        last_block=curr_block
                    # Else
                    else:
                        # We leave the loop because there are not any more data
                        break
                    if b'\xFF' in dexor:
                        dexor = dexor.replace(b'\xFF','')
                    # We write the deciphered data to the output stream
                    buffer_out.write(dexor)
                    # Iterate the counter
                    iteration+=1

    # Encrypt CBC function
    def crypt(self):
        #generate 256bit key (sha256bits)
        key = self.hashing_key(self.key)
        # The last block is our initialisation vector
        last_block = self.IV
        # Init the blocks counter
        iteration = 0
        # Displaying initialisation vector
        print("IV : 0x" + last_block.encode('hex'))
        # Open input and output streams
        # Input file is open as buffer_in with read permission
        with open(self.file_in, "rb") as buffer_in:
            with open(self.file_out, "wb") as buffer_out:
                #storing IV
                buffer_out.write(last_block)
                while True:
                    # We get the current block 
                    curr_block = buffer_in.read(self.block_size_bytes)
                    # We get the current length block 
                    curr_len = len(curr_block)

                    # If current block is empty 
                    if curr_len <= 0:
                        # Display Done
                        print 'Done!'
                        break #EOF

                    # If current block length is lower than the block size
                    if curr_len < self.block_size_bytes:
                        # Then we add padding
                        curr_block += self.padding(self.block_size_bytes - curr_len)
                    # Then we xor the current block with the last block and encrypt it with the key
                    enxor = self.xor_crypt(self.xor_crypt(curr_block,last_block),key)
                    # Encoding in utf-8
                    enxorUtf = enxor.encode()
                    # Display the number of the block and the encrypt content
                    print('=============================================================')
                    print("# Cipher block N°" + str(iteration) + " with hashed key 0x" + key.encode('hex')) 
                    print("# Cipher block : " + enxorUtf)
                    print('=============================================================')
                    
                    # Then the last_block var takes the value of the encrypted block
                    last_block = enxor
                    # Iterate the counter
                    iteration += 1
                    # We write the ciphered data to the output stream
                    buffer_out.write(enxor)