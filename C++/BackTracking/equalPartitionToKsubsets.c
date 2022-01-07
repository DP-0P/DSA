 bool solve(int sum,int s,int k,vector<bool> booleanArray,int index, int n,int arr[]){
      if(k==1)
        return true;
        
    if(sum>s)
        return false;
        
    if(sum == s)
        return solve(0,s,k-1,booleanArray,0,n,arr);
    
    for(int i = index;i<n;i++){
        if(booleanArray[i] == false){
            booleanArray[i] = true;
            if(solve(sum+arr[i],s,k,booleanArray,i+1,n,arr))
                return true;
            else booleanArray[i] = false;
        }
  }
    return false;
  }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k == 0)
            return 0;
        
        if(k==1)
            return 1;
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
            sum += a[i];
        
        if(sum%k != 0)
            return false;
        
        vector<bool> booleanArray(n,false);
        return solve(0,sum/k,k,booleanArray,0,n,a);
    }