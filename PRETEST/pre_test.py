# -*- coding: utf-8 -*-
"""
Created on Tue May 11 18:13:26 2021

@author: user
"""

import random
from key_generate import key_generate
from Crypto.Util import number

KEY = key_generate(512)
print(f'N = {KEY.N}, N length = {number.size(KEY.N)}')
print(f'Phi = {KEY.phi}')
print(f'public key = {KEY.pub}, pub key length = {number.size(KEY.pub)}')
print(f'private key = {KEY.pri}, pri key length = {number.size(KEY.pri)}')


message = pow(2, 6)
ciphertext = KEY.encode(message)
print(f'ciphertext = {ciphertext}')
plaintext = KEY.decode(ciphertext)
print(f'plaintext = {plaintext}')
if plaintext == message:
    print('RSA is work!')
