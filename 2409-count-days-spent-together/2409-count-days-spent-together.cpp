class Solution {
public:

    int findnumber(string date , vector<int> cumsum)
    { 
        int mon = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return cumsum[mon -1] + days;
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthdays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumsum(13 ,0);

        cumsum[1] = 31;
        for(int i = 2; i<= 12 ; i++)
        {
            cumsum[i] = cumsum[i-1] + monthdays[i-1];
        }

        int arriveAliceDay = findnumber(arriveAlice ,cumsum );
        int leaveAliceDay  = findnumber(leaveAlice ,cumsum);
        int arriveBobDay   = findnumber(arriveBob ,cumsum);
        int leaveBobDay    = findnumber(leaveBob ,cumsum);

        int overlap =  min(leaveAliceDay , leaveBobDay) - max(arriveAliceDay ,arriveBobDay) + 1;

        return overlap > 0 ? overlap : 0;

    }
};