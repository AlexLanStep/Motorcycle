
import subprocess

from smb import SMBConnection

class SMBClient:
    def __init__(self, ip, username, password, servername, share_name):
        self._ip = ip
        self._username = username
        self._password = password
        self._port = 445
        self._share_name = share_name
        self._servername = servername
        self._server = ''

    def _connect(self):
        """ Connect and authenticate to the SMB share. """
        self._server = SMBConnection(username=self._username,
                                    password=self._password,
                                    my_name=self._get_localhost(),
                                    remote_name=self._servername,
                                    use_ntlm_v2=True)
        self._server.connect(self._ip, port=self._port)

    def module(self):
        k=1

    def _download(self, files: list):
        """ Download files from the remote share. """
        for file in files:
            with open(file, 'wb') as file_obj:
                self._server.retrieveFile(service_name=self._share_name,
                                          path=file,
                                          file_obj=file_obj)

    def _get_localhost(self):
        self._host = subprocess.Popen(['hostname'],stdout=subprocess.PIPE).communicate()[0].strip()

_file = r"\\10.102.1.88\data\02_Users_Folders\Mizin\4_IPG\1_MotorcycleMaker\2_LOGS\1_LOGS_RAW"
_file = _file+'\\' + "NAMILog1_test.csv"
filename = [_file]
smb_client = SMBClient(ip='10.102.1.88', username='Lanin', password='123456', servername='SERVER', share_name='SHARE_NAME')
smb_client._connect()
response = smb_client._download(filename)


'''
from ftplib import FTP, error_perm
import os
import glob
def walk(cd):
    ftp.cwd(cd)
    print(cd)
    print(ftp.retrlines('LIST'))
    for i in ftp.nlst():
        host_file = os.path.join('\\10.102.1.88\\data\\02_Users_Folders\\Mizin\\4_IPG\\1_MotorcycleMaker\\2_LOGS\\1_LOGS_RAW', i)
        try:
            walk(cd+i+"/")
        except error_perm:
            print(i)
            with open(host_file, 'wb') as local_file:
                ftp.retrbinary('RETR ' + i, local_file.write)
# ftp = FTP(host='\\10.102.1.88\\data\\02_Users_Folders\\Mizin\\4_IPG\\1_MotorcycleMaker\\2_LOGS\\1_LOGS_RAW',

# ftp = FTP(host='\\10.102.1.88\\data\\02_Users_Folders\\Mizin\\4_IPG\\1_MotorcycleMaker\\2_LOGS\\1_LOGS_RAW',
#           user='Lanin',
#           passwd='123456')

with FTP(host=r'\\10.102.1.88', user='Lanin',passwd='123456') as ftp:
    ftp.login()
    d =ftp.dir()
    k=1


# ftp.login("", '')
# cd = "/"
# walk(cd)
# ftp.quit()

'''
