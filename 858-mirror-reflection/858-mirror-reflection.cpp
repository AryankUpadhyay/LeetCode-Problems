class Solution {
public:
    int mirrorReflection(int p, int q) {
        int movement =1, direction=1;
        int yCordinate=0;
        int left=p;
        while(left%q!=0){
            int quo=left/q;
            int rem=left%q;
            left=p-(q-rem);
            if(quo%2==0){
                direction=(direction+1)%2;
            }
            movement++;
        }
        direction=(direction+(left/q))%2;
        if(direction==1){
            return 2;
        }
        if(movement%2==0){
            return 0;
        }
        return 1;
    }
};