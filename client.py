import requests
import os
import sys
import time
n = len(sys.argv)
print(n)
if n != 3:
	print("please give correct args")
	exit()

key = sys.argv[1]
path = sys.argv[2]
print(path)
sent_files = set()
while True:
	try:
		files = os.listdir(path)
	except Exception as e:
		print("error in listing files")
		exit()
	
	for file in files:
		try:
			if file in sent_files:
				continue
			file_path = path + '/' + file
			f = open(file_path, 'rb')

			ff = {"myFile": f}

			res = requests.post('http://' + key + ".ngrok.io/upload", files = ff)
			print(res)
			f.close()
			sent_files.add(file)
			time.sleep(1)
		except Exception as e:
			print(e)
			pass
	
	time.sleep(1)
	