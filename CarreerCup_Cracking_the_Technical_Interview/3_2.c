/*
 * 题目描述：实现一个栈，包含三个方法：push pop min，其中min函数返回栈中的最小值，三个方法的时间复杂度必须是O(1).
 * Author：赵庶林
 * Date：2014/08/14
 */

/*
 * 思路：开辟两个数组：一个用于实现栈，一个用于记录最小值。
 *       最小值数组里面存放的是一个结构体：最小值+引用计数。
 *       每次push新数据，判断：
 *                             if(new < min) then push (new, 1) into min[]
 *                             if(new >= min) then ref ++
 *       每次pop，ref --; 判断ref是否=0了。
 */




