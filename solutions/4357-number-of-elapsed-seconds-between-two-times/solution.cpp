class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sh = stoi(startTime.substr(0, 2));
        int sm = stoi(startTime.substr(3,2));
        int ss = stoi(startTime.substr(6,2));

        int eh = stoi(endTime.substr(0,2));
        int em = stoi(endTime.substr(3,2));
        int es = stoi(endTime.substr(6,2));

        int start = sh * 3600 + sm * 60 + ss;
        int end = eh * 3600 + em * 60 + es;
        return end - start;
    }
};
