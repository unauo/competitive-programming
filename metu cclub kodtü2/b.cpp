#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, std::vector<int>> limits = {
    {30, {30,120,1020,10020,100020}},
    {42, {42,126,1008,10038,100002}},
    {66, {66,132,1056,10032,100056}},
    {78, {78,156,1014,10062,100074}},
    {102, {-1,102,1020,10098,100062}},
    {114, {-1,114,1026,10032,100092}},
    {70, {70,140,1050,10010,100030}},
    {110, {-1,110,1100,10010,100100}},
    {130, {-1,130,1040,10010,100100}},
    {170, {-1,170,1020,10030,100130}},
    {190, {-1,190,1140,10070,100130}},
    {154, {-1,154,1078,10010,100100}},
    {182, {-1,182,1092,10010,100100}},
    {238, {-1,238,1190,10234,100198}},
    {266, {-1,266,1064,10108,100016}},
    {286, {-1,286,1144,10010,100100}},
    {374, {-1,374,1122,10098,100232}},
    {418, {-1,418,1254,10032,100320}},
    {442, {-1,442,1326,10166,100334}},
    {494, {-1,494,1482,10374,100282}},
    {646, {-1,646,1292,10336,100130}},
    {105, {-1,105,1050,10080,100065}},
    {165, {-1,165,1155,10065,100155}},
    {195, {-1,195,1170,10140,100035}},
    {255, {-1,255,1020,10200,100215}},
    {285, {-1,285,1140,10260,100035}},
    {231, {-1,231,1155,10164,100023}},
    {273, {-1,273,1092,10101,100191}},
    {357, {-1,357,1071,10353,100317}},
    {399, {-1,399,1197,10374,100149}},
    {429, {-1,429,1287,10296,100386}},
    {561, {-1,561,1122,10098,100419}},
    {627, {-1,627,1254,10032,100320}},
    {663, {-1,663,1326,10608,100113}},
    {741, {-1,741,1482,10374,100035}},
    {969, {-1,969,1938,10659,100776}},
    {385, {-1,385,1155,10010,100100}},
    {455, {-1,455,1365,10010,100100}},
    {595, {-1,595,1190,10115,100555}},
    {665, {-1,665,1330,10640,100415}},
    {715, {-1,715,1430,10010,100100}},
    {935, {-1,935,1870,10285,100045}},
    {1045, {-1,-1,1045,10450,100320}},
    {1105, {-1,-1,1105,11050,100555}},
    {1235, {-1,-1,1235,11115,100035}},
    {1615, {-1,-1,1615,11305,100130}},
    {1001, {-1,-1,1001,10010,100100}},
    {1309, {-1,-1,1309,10472,100793}},
    {1463, {-1,-1,1463,10241,100947}},
    {1547, {-1,-1,1547,10829,100555}},
    {1729, {-1,-1,1729,10374,100282}},
    {2261, {-1,-1,2261,11305,101745}},
    {2431, {-1,-1,2431,12155,102102}},
    {2717, {-1,-1,2717,10868,100529}},
    {3553, {-1,-1,3553,10659,103037}},
    {4199, {-1,-1,4199,12597,100776}},
};

bool repcheck(std::string &rep, std::string &num, int n){
    //std::cout << "repcheck" << " " << rep << " " << num << " " << n << "\n";
    int map[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    for(int i=0; i<n; i++){
        char &x = rep[i];
        char &y = num[i];
        int z = map[x-97];
        //std::cout << x << " " << y << " " << z << "\n";
        if(z == -1 || z == y){
            map[x-97] = y;
        } else {
            return false;
        }
    }
    return true;
}


int main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    int m = a*b*c;
    int q;
    std::cin >> q;
    for(int i=0; i<q; i++){
        std::string rep;
        std::cin >> rep;
        int d = rep.size();
        if(d < 2){
            std::cout << "-1" << std::endl;
            continue;
        }
        long l = limits[m][d-2];
        if(l == -1){
            std::cout << "-1" << std::endl;
        }
        else {
            long pp = std::pow(10,d);
            for(; l<pp; l+=m){
                std::string ls = std::to_string(l);
                if(!(repcheck(rep,ls,d))) continue;
                else{
                    std::cout << l << std::endl;
                    break;
                }
            }
            if(l>pp) std::cout << -1 << std::endl;
        }
    }
}