class Solution {
public:
int maxArea(vector& height) {
int area=0;
int l= 0; //(left-most height}
int r= height.size()-1; //(right-most height)
while(l<r){
int h=min(height[l], height[r]);  //(we calculate minimum height so that it is common for both l and r i.e., this minimum height appears in both l and r)
area= max(area, (r-l)*h);
if(height[l]<=h && l<r) l++;    //(if next height is not greater than h we move forward)
if(height[r]<=h && l<r) r--;     //(if previous height is not greater than h we move backwards)
}
return area;
}
};
