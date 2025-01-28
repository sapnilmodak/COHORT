#include <bits/stdc++.h>
using namespace std;

struct Player_details{
    int cur_sum; 
    int cur_cnt;
    Player_details(){
        cur_sum = 0;
        cur_cnt = 0;
    }
    void insert(int x){
        cur_sum += x;
        cur_cnt ++;
    }
    double get_sum(){
        return cur_sum;
    }
    double get_mean(){
        return double(cur_sum)/cur_cnt;
    }
    map<string,double> get_details(){
        map<string,double> details;
        details["mean"]= get_mean();
        details["sum"]= get_sum();
        return details;
    }
};

struct Dashboard{
    map<string,Player_details> mp;
    
    void ingest(string player, int score){
        mp[player].insert(score);
    }
    map<string,double> get_details(string  player){
        return mp[player].get_details();
    }
};

int main()
{
    Dashboard mydash;
    mydash.ingest("virat",6);
    mydash.ingest("dhoni",2);
    mydash.ingest("virat",0);
    
    auto data = mydash.get_details("virat");
    for(auto v:data){
        cout<<v.first<<" "<<v.second<<endl;
    }
}