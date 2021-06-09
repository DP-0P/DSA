import java.util.Arrays;

public class array4 {
    public static void main(String[] args) {
        int a[] = {0,2,1,2,1,2,0,1,0};

        System.out.println(Arrays.toString(sorting012(a)));

        System.out.println(Arrays.toString(sorting012ButNooberMethod(a)));
    }

    public static int[] sorting012(int a[]) {
        int low = 0, high = a.length - 1, mid = 0;

        for (int i = 0; i < a.length; i++) {
            if (a[mid] == 0) {
                a[low] ^= a[mid];
                a[mid] ^= a[low];
                a[low] ^= a[mid];
                low++;
                mid++;
            }

            else if (a[mid] == 1)
                mid++;

            else {
                a[high] ^= a[mid];
                a[mid] ^= a[high];
                a[high] ^= a[mid];
                high--;
            }
        }
        return a;
    }

    public static int[] sorting012ButNooberMethod(int a[]){
        int c0=0,c1=0,c2=0;
        for(int i=0;i<a.length;i++){
            if(a[i]==0)
            c0++;

            else if(a[i]==1)
            c1++;

            else 
            c2++;
        }
        int i=0;

        while(c0>0){
            a[i]=0;
            i++;
            c0--;
        }

        while(c1>0){
            a[i]=1;
            i++;
            c1--;
        }

        while(c2>0){
            a[i]=2;
            i++;
            c2--;
        }
        return a;
    }
}