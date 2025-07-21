class Solution {
public:
//    bool isPrime(int num){
//     if(num>2 ) return false;
//     for(int i = 2;i * i <= num;i++){
//         if(num % i ==0) return false;

//     }
//     return true;
//    }

//     bool isThree(int n) {
//         int root = sqrt(n);

//         return root * root ==n  && isPrime(root);


bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    bool isThree(int n) {
        int root = sqrt(n);
        return root * root == n && isPrime(root);
    }
        
    
};