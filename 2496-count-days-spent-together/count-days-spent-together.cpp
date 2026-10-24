class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int ans = 0;
        vector<vector<int>>alice(13, vector<int>(32,0));   
        vector<vector<int>>bob(13, vector<int>(32,0));     
        vector<int>days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aa = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0');   
        int la = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0');
        int ab = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0');
        int lb = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0');

        for(int i = aa; i<= la; i++){
            int ad = i == aa? (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0'): 1;   
            int ld = i == la? (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0'): days[i-1];
            for(int j = ad; j<=ld; j++){
                alice[i][j]++;
            }
        }

        for(int i = ab; i<= lb; i++){
            int ad = i == ab? (arriveBob[3]-'0')*10 + (arriveBob[4]-'0'): 1;       
            int ld = i == lb? (leaveBob[3]-'0')*10 + (leaveBob[4]-'0'): days[i-1];
            for(int j = ad; j<=ld; j++){
                bob[i][j]++;
            }
        }

        for(int i = 1; i<=12; i++){      
            for(int j = 1; j<32; j++){
                if(alice[i][j]>0 && bob[i][j]>0) ans++;
            }
        }

        return ans;
    }
};