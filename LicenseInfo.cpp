#include "LicenseInfo.h"

int WriterLicenseFile(const char *machineInfo, licenseInfo *pl, const char *outputFileName,const char* key= nullptr){
  if(key == nullptr){
    AES aes;
    return aes.WriterLicenseFile(machineInfo,&pl, outputFileName);
  }else{
    AES aes(key);
    return aes.WriterLicenseFile(machineInfo,&pl, outputFileName);
  }
}

int ReadLicenseFile(const char *outputFileName, licenseInfo *pl, char *md5sum,const char* key= nullptr){
  if(key == nullptr){
    AES aes;
    return aes.ReadLicenseFile(outputFileName, &pl, md5sum);
  }else{
    AES aes(key);
    return aes.ReadLicenseFile(outputFileName, &pl, md5sum);
  }
}