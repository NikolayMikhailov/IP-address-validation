#include <iostream>
#include <string>


std::string ipAddress;
int counterOctedOne = 0; int counterOctedTwo = 0;
int counterOctedThree = 0; int counterOctedFour = 0;
int countePoint = 0;
void numberСharacters(std::string ipAddress){
  for (int i = 0; i<ipAddress.length(); ++i){
    if(ipAddress[i] == '.'){
      ++countePoint;
    }
    if (ipAddress[i] != '.' && countePoint==0) {
   ++counterOctedOne;
    }
     if (ipAddress[i] != '.' && countePoint==1) {
   ++counterOctedTwo;
   
    }  
      if (ipAddress[i] != '.' && countePoint==2) {
   ++counterOctedThree;
    } 
      if (ipAddress[i] != '.' && countePoint==3) {
   ++counterOctedFour;
    }   
  }    
}
std::string OctetOne; std::string OctetTwo; 
std::string OctetThree; std::string OctetFour;
void writinglines(int counterOctedOne,int counterOctedTwo,int counterOctedThree,int counterOctedFour){
   OctetOne.resize(counterOctedOne);
   OctetTwo.resize(counterOctedTwo);
   OctetThree.resize(counterOctedThree);
   OctetFour.resize(counterOctedFour); 
  for (int i = 0; i<ipAddress.length(); ++i){
    if(i<counterOctedOne){
      OctetOne[i] = ipAddress[i];
    }
    else if(i>counterOctedOne && i<=counterOctedOne+counterOctedTwo){
      OctetTwo[i-counterOctedOne-1] = ipAddress[i];
    }
    else if(i>counterOctedOne+counterOctedTwo+1 && i<=counterOctedOne+counterOctedTwo+counterOctedThree+1){
      OctetThree[i-(counterOctedOne+counterOctedTwo+2)] = ipAddress[i];
    }
    else if(i>counterOctedOne+counterOctedTwo+counterOctedThree+2 && i<ipAddress.length()){
      OctetFour[i - (counterOctedOne+counterOctedTwo+counterOctedThree+3)] = ipAddress[i];
    }
  }

}
int one, two, three, four; bool nummberOTTF = false;
void Numbers(std::string OctetOne,std::string OctetTwo,std::string OctetThree,std::string OctetFour){
 one = std::atoi(OctetOne.c_str());
 two = std::atoi(OctetTwo.c_str());
 three = std::atoi(OctetThree.c_str());
 four = std::atoi(OctetFour.c_str());
 one>=0 && one<256 && two>=0 && two<256 && three>=0 && three<256 && four>=0 && four<256  && counterOctedOne!=0 && counterOctedTwo !=0 && counterOctedThree !=0 && counterOctedFour !=0 ? nummberOTTF = true : nummberOTTF = false;
}

   bool pCheck = true;
  bool preliminaryCheck(std::string ipAddress){
   for (int i = 0; i<ipAddress.length(); ++i){
    if(ipAddress[i] == '.' && ipAddress[i+1] == '.'){
      pCheck = false;
      }
    if (ipAddress[i] == '.' && ipAddress[i+1] == '0' && ipAddress[i+2] != '.'|| ipAddress[0] == '0'){
        pCheck = false;
      }
    if(ipAddress[0] == '.' || ipAddress[ipAddress.length()-1] == '.'){
        pCheck = false;
      }
    if(ipAddress[i]<48  && ipAddress[i] !=46 || ipAddress[i]>57){
        pCheck = false;
      }
    if (ipAddress[0]==' '){
        pCheck = false;
      } 
    }
    return pCheck;
  }
   
int main() {
  std::cout << "Hello! This program validates the IP address\n";
  std::cout << "============================================\n";
  std::cout << "Enter the IP address: ";  
  getline(std::cin, ipAddress);
  preliminaryCheck(ipAddress);
  if(pCheck == false){
    std::cout<<"Invalid\n";
  } else{ 
  numberСharacters(ipAddress);
  writinglines(counterOctedOne, counterOctedTwo,counterOctedThree, counterOctedFour);
  Numbers(OctetOne,OctetTwo,OctetThree,OctetFour);
    if(nummberOTTF == false){
      std::cout<<"Invalid\n";
    } else {std::cout<<"Valid\n";}
  }
}