# -*- coding: utf-8 -*-
"""
Created on Wed May 12 17:28:09 2021

@author: user
"""
from Crypto.Util import number

class key_generate():
    def __init__(self, bitlength):
        p_len = 0
        q_len = 0
        if bitlength == 512:
            p_len = 200
            q_len = 312
        elif bitlength == 1024:
            p_len = 312
            q_len = 712
        elif bitlength == 2048:
            p_len = 712
            q_len = 1336
        elif bitlength == 32:
            p_len = 8
            q_len = 24
        elif bitlength == 128:
            p_len = 40
            q_len = 88
        else:
            return 0
        
        while 1:
            p = number.getPrime(p_len) # return upto p_len bits prime
            q = number.getPrime(q_len) # return upto q_len bits prime

            N = p*q
            self.N = N # N is public key
            phi = (p-1)*(q-1)
            self.phi = phi
            
            d = number.getRandomInteger(bitlength)
            self.pri = d
            e = number.inverse(d, phi)
            self.pub = e
            if e*d % phi == 1:
                break
        
    def encode(self, message):
        return pow(message, self.pub, self.N)
    def decode(self, ciphertext):
        return pow(ciphertext, self.pri, self.N)





