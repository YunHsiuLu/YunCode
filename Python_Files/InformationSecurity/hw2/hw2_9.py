import datetime
import random
from base64 import b64encode, b64decode
from binascii import unhexlify

from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

# lab time is 2018,4,17,23,8,49
# I have not download the environment
# test from 2 hrs ago
date_seed = int((datetime.datetime(2018,4,17,21,8,49)).timestamp())

iv = "09080706050403020100a2b2c2d2e2f2"
msg = b"\x25\x50\x44\x46\x2d\x31\x2e\x35\x0a\x25\xd0\xd4\xc5\xd8\x0a\x34"
iv = unhexlify(iv)
password = ""
for s in range(3601):
	random.seed(date_seed)
	for i in range(16):
		password += hex(random.randint(0,255))

	password = unhexlify(password)

	# padding
	msg = pad(msg, AES.block_size)

	# Encipher Text
	cipher = AES.new(password, AES.MODE_CBC, iv)
	cipher_text = cipher.encrypt(msg)

	# Encode Cipher_text as Base 64 and decode to String
	out = b64encode(cipher_text).decode('utf-8')
	print(f"OUT: {out}")

	# Decipher cipher text
	decipher = AES.new(password, AES.MODE_CBC, iv)
	try:
	    # UnPad Based on AES Block Size
	    plaintext = unpad(decipher.decrypt(b64decode(out)), AES.block_size).decode('utf-8')
	except:
	    print("padding is incorrect")
	else:
	    print(f"PT: {plaintext}")
	    print(f"Pwd: {password}")