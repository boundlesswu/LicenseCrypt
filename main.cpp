#include <iostream>
#include <cstdio>

#include "AES.h"
#include "LicenseInfo.h"

void print(unsigned char* state)
{
  int i;
  for(i=0; i<16; i++)
  {
    printf("%s%X ",state[i]>15 ? "" : "0", state[i]);
  }
  printf("\n");
}

int main() {
#if 1
  licenseInfo info;
  info.starTime = time(nullptr);
  info.endTime = info.starTime + 3600*24*365;
  info.validTime = 3600*24*365;
  info.loginTime = time(nullptr);
  info.maxCallNum = 500000L;
  info.maxChannelNum =  64;
  info.functionBit = 0x678;

  display(&info);

  const char md5sum[]="cf9ab2ad53648f0e0e32493b291c7090";
  const char licenseFileName[]="license.dat";

  AES aes;

  aes.WriterLicenseFile(md5sum,&info, licenseFileName);

  licenseInfo licenseInfo1 ;
  char machineInfo[32+1] = {0};
  aes.ReadLicenseFile(licenseFileName, &licenseInfo1, machineInfo);
  std::cout << "ms5sum:" <<machineInfo<<std::endl;
  display(&licenseInfo1);
#else
  unsigned char key[] =
    {
      0x2b, 0x7e, 0x15, 0x16,
      0x28, 0xae, 0xd2, 0xa6,
      0xab, 0xf7, 0x15, 0x88,
      0x09, 0xcf, 0x4f, 0x3c
    };
  AES aes(key);
  aes.WriterLicenseFile("md5sum", "(const char *) a", "license.dat");
#endif

  return 0;
}


