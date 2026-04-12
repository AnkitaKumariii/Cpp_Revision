class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> newAngle;
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        double s = (a + b + c) / 2.0; 
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        if(area > 0) {
            double angleC = acos((a*a + b*b - c*c) / (2*a*b));
            angleC = angleC * 180 / M_PI;
            newAngle.push_back(angleC);

            double angleB = acos((a*a + c*c- b*b) / (2*a*c));
            angleB = angleB * 180 / M_PI;
            newAngle.push_back(angleB);

            double angleA = acos((b*b + c*c - a*a) / (2*b*c));
            angleA = angleA * 180 / M_PI;
            newAngle.push_back(angleA);
        }
        sort(newAngle.begin(), newAngle.end());
        return newAngle;
    }
};
