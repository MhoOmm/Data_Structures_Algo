// MLE
class Solution {

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n  = classes.size();
        vector<double>PR(n);
        for(int i =0;i<n;i++)
        {
            PR[i] = (double)classes[i][0]/classes[i][1];
        }

        while(extraStudents--)
        {
            vector<double>updatedPr(n);
            for(int i=0;i<n;i++)
            {
                double newR  = double(classes[i][0] +1)/(classes[i][1]+1);
                updatedPr[i] = newR; 
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { 
                double delta = updatedPr[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPr[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; 
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};


