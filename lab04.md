# 排序算法

## 时间复杂度
&emsp;在介绍各类排序算法前，须要先说明算法的时间复杂度的概念。
>在计算机科学中，算法的时间复杂度是一个函数，它定性描述了该算法的运行时间。这是一个关于代表算法输入值的字符串的长度的函数。时间复杂度常用大O符号表述，不包括这个函数的低阶项和首项系数。

&emsp;简单说，就是我们用O来表示变量n（在排序算法中，指待排序的数字个数）大小与算法程序运行时间的关系。比如,若运行时间与n成线性关系，则时间复杂度为O(n)，若与n的平方成线性关系，则为O(n<sup>2</sup>)。**算法的时间复杂度直接代表了算法的高效程度。**

## O(n<sup>2</sup>)
&emsp;时间复杂度为O(n<sup>2</sup>)的排序算法是最简单，也是效率最普通的一种。我们常见的有冒泡、插入、选择。在本模块我们只介绍插入排序。

```c++
int insertion_sort(int *arr, int low, int high){
	int tmp, i, j;
	for(i = low + 1; i <= high; i++){
		tmp = arr[i];
		for(j = i - 1; j >= low; j--){
			if(tmp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j+1] = tmp;
	}
}
```
<center><img src="images/Insertion_sort.gif"><br>插入排序</center>

&emsp;很明显，函数中有两层大约为n次的循环，时间复杂度自然就是O(n<sup>2</sup>)。第一层循环对所有待排序的数进行遍历，第二层循环对第一层循环所遍历到的数 的之前的已经排序好的数进行遍历，若之前的数比这一个数大，则向后移一位，直到找到这个数的位置。

## O(nlogn)

&emsp;这个复杂度级别的排序算法较前一个在效率上有了质的飞跃，而且其优势在数组长度越大时越凸显。O(nlogn)的排序算法主要有归并排序以及快速排序，这两个是我们在学习算法的前期所能接触的最高效的排序算法，其难度比O(n<sup>2</sup>)高一个台阶，然而在所有算法中，也是十分基础的必备算法。本模块我们只介绍快速排序。

```c++
int quickSort(int a[], int left, int right)
{
　　int i = left;
　　int j = right;
　　int temp = a[left];
　　if(left >= right)
　　　　return 0;
　　while(i != j)
　　{
　　　　while(i < j && a[j] >= temp) 
　　　　j--;
　　　　if(j>i)
　　　　　　a[i]=a[j];
　　　　while(i < j && a[i] <= temp)
　　　　i++;
　　　　if(i < j)
　　　　　　a[j] = a[i];
　　}
　　a[i] = temp;
　　quickSort(a, left, i-1);
　　quickSort(a, i+1, right);
}

```

<center><img src="images/quicksort.gif"><br>快速排序</center>

&emsp;快排和归并一样采用分治的思维，大大减小了排序时遍历数组的次数。快排先在待排序数组中随机选取一个轴枢，将比轴枢大的数放在轴枢右边，小的放在左边，然后对两边区间进行递归，最终正确排序。
&emsp;尽管乍一看很厉害，但是快排在遇到较坏的情况时，比如有数组大部分为重复数，这时候，算法的时间复杂度会退化为O(n<sup>2</sup>)，所以要完全发挥其优势，还需要许多优化，例如三数取中选轴枢，提前处理重复数等。