class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head){

        List<Integer> arr = new ArrayList<>();

        int pre = -1;
        int pos = 1;
        while(head.next != null){
            if(pre != -1){
                if(pre < head.val && head.val > head.next.val || pre > head.val && head.val < head.next.val)
                    arr.add(pos);
            }
            pos += 1;
            pre = head.val;
            head = head.next;
        }
        
        if(arr.size() <= 1)
            return new int[]{-1,-1};

        int mn = (int)1e5;
        pre = -1;
        for(int x : arr){
            if(pre != -1)
                mn = Math.min(mn,x - pre);
            pre = x;
        }

        return new int[]{mn,arr.get(arr.size() - 1) - arr.get(0)};
    }
}