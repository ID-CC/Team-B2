import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;

        Arrays.sort(lost);
        Arrays.sort(reserve);

        for(int i=0; i<lost.length; i++) {
            for(int j=0; j<reserve.length; j++) {
                if(lost[i] == reserve[j]) {
                    answer++;
                    lost[i] = -1;
                    reserve[j] = -1;
                    break;
                }
            }
        }

        for(int k=0; k<lost.length; k++) {
            for(int l=0; l<reserve.length; l++) {
                if(lost[k] == reserve[l]-1 || lost[k] == reserve[l]+1) {
                    answer++;
                    lost[k] = -1;
                    reserve[l] = -1;
                    break;
                }
            }
        }

        return answer;
    }
}