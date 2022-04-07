# 链表Oj

#### ==首先思考大致思路，然后在着眼于具体实现步骤。==

[6. 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。]([链表分割_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking))

![image-20211230143140874](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20211230143140874.png)

要是不要求改变相对顺序就可以定义两个指针 head 和 tail 大于x的头插，小于x的尾插

如果一眼看不出来错误就用排除法，把代码注释掉，再去看他报不报错，把报错部分屏蔽掉。

一般情况oj是不会限制空间复杂度的，内存超出限制原因通常是程序会有死循环等等一些问题导致的，



![image-20211230155331713](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20211230155331713.png)

如果报错出现一堆数据，先选择一个简单的测试用例进行测试，如果一个简单的用例有问题，应该高兴，如果不报测试用例就应该思考极端情况，检查哪里有死循环，就要思考边界 一般都是头啊 尾啊 空指针的情况。

![image-20211230155246446](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20211230155246446.png)

不同的平台检查严格的机制性不一样，所以从vs或者牛客能过，力扣不能过都很正常。

实在找不出来就放到vs下面调试。

![image-20211230160244188](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20211230160244188.png)

定义两个哨兵位的头节点，小于放less,大于放在greater

![image-20211230160419597](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20211230160419597.png)

[7.链表的回文结构。]([链表的回文结构_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking))

![image-20220104142737369](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220104142737369.png)

首先实现两个函数，寻找链表中间节点和逆序链表的函数

![image-20220104142953267](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220104142953267.png)

大致思路为找到链表中间节点，然后将中间节点后面的代码逆序过来，从链表的头部和逆序过来的头开始遍历，判断两个链表的val是否相等，不管链表的长度是奇数个还是偶数个，回文结构的链表NULL指针之前的val总是相等的，

![image-20220104144218944](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220104144218944.png)

因为逆序完后的前面的链表依然连接着最后一个，他们NULL指针之前val依然相等。偶数个的链表到NULL结束。



![image-20220104143131581](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220104143131581.png)

最后判断rm是否为NULL, 链表为偶数个时，ra的长度比rm多一个，ra尾部还链接着rm的尾部，所以判断NULL指针需要判断rm为空的情况来判定链表是否为还回文结构。

![image-20220104144551806](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220104144551806.png)

[8.输入两个链表，找出它们的第一个公共结点。]([160. 相交链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/))

![image-20220107175151839](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220107175151839.png)

首先遍历两个链表同时求出两个链表长度，尾节点（地址）相同即为相交，否则返回NULL。

![image-20220107175443460](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220107175443460.png)

[ 9.给定一个链表，判断链表中是否有环。]()[141. 环形链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/linked-list-cycle/description/)

![ ](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220107175710165.png)

[10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL]([142. 环形链表 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/linked-list-cycle-ii/description/))

链表带环不能用正常的方式去遍历，因为会造成死循环。

引用之前的快慢指针，slow走一步，fast走两步。

让一个指针从链表起始位置开始遍历链表，同时让一个指针从判环时相遇点的位置开始绕环运行， 两个指针都是每次均走一步，最终肯定会在入口点的位置相遇。 证明  

![image-20220108150024110](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220108150024110.png)

链表的经典  图二带环形式为循环链表

![image-20220108150411678](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220108150411678.png)

![image-20220108150443721](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220108150443721.png)

==证明过程==

![image-20220108152908284](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220108152908284.png)

**自己画图**

![image-20220108153105837](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220108153105837.png)

