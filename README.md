# QSocketTools
一个基于Qt5的Socket调试工具

--------------2016/05/11------------------
完成TCP客户端的基本功能
1.可以和服务器连接，并相互传输数据；
2.服务端断开连接时，客户端能根据消息，做提示；
3.显示本地的端口和ip

未完成：
1.使用自定义协议收发功能未完成

Bug:
1.连接本地服务器时，只能使用 127.0.0.1进行连接，无法使用ip地址连接
(已修复)

## 增加UDP广播功能  
bug:
1:由于Qt版本造成无法使用中文进行编程注释以及文本输入，后期将降低Qt版本，当前为Qt5.5


代码重构


