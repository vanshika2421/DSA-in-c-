
vector<int> reversedd(vector<int> arr){
    int s = 0; 
    int e = arr.size() -1 ;
    while(s<=e){
         swap(arr[s++], arr[e--]);
    }
    return arr;
}

int addArray(vector<int> arr, vector<int> brr){
    int n =arr.size();
    int m = brr.size();
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int> ans;
    while(i >= 0 && j >= 0){
        int val1 =arr[i];
        int val2 = brr[j];
        // int carry = 0;
        int sum = val1 + val2 + carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i >= 0 ){
        
        int carry = 0;
        int sum = arr[i] + carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0){
      
       
        int sum = brr[j]+ carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while(carry != 0){
        int sum =  carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return reversedd(ans);
}

int main(){

    vector<int> arr;
    vector<int> brr;
    int m,n;
    // int brr[m];
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0; i < m; i++){
        cin >> num;
        brr.push_back(num);
        // cin >> brr[i];
    }
   
    addArray(arr,brr);
}