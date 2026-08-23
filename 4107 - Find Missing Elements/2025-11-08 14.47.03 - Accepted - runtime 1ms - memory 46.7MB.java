class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> ls=new ArrayList<>();
        int min=100000;
        int max=0;
        for(int i=0;i<nums.length;i++){
            min=Math.min(nums[i],min);
            max=Math.max(nums[i],max);
        }
        // System.out.println(min+" "+max);
        boolean f[]=new boolean[max-min+1];
        for(int i=0;i<nums.length;i++){
            f[nums[i]-min]=true;
            //   System.out.println(nums[i]-min);
        }
        for(int i=0;i<f.length;i++){
            if(f[i]==false){
                ls.add(min+i);
            }
        }
        return ls;
    } 
}