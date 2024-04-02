Kyle Patrick Roland M. Francisco &
Luis Jaime Rafayel
# 1-D stencil of vector X in vector Y

## KERNEL EXECUTION TIME ANALYSIS

| Mode       | Exponent | C (seconds) | x86-64 (seconds) |
|------------|----------|-------------|-------------------|
| Debug      | 2^20     | 0.00600     | 0.000000          |
| Debug      | 2^24     | 0.10000     | 0.000000          |
| Debug      | 2^30     | 5.39100     | 10.74800          |
| Release    | 2^20     | 0.00600     | 0.009000          |
| Release    | 2^24     | 0.07500     | 0.138000          |
| Release    | 2^30     | 4.56600     | 8.748000          |

In Debug mode, negligible execution times, close to 0 seconds, are observed for smaller problem sizes such as 2^20, however as the problem size increases, execution times escalate notably, reaching 5.391 seconds for an exponent of 2^30.
<br> Release mode exhibits significantly faster execution times across all problem sizes, with shorter execution times compared to Debug mode. For instance, at 2^20, Release mode shows execution times of 0.006 seconds for C and 0.009 seconds for x86-64, which shows improved performance. However, even in Release mode, larger problem sizes cause longer execution times, with the largest exponent of 2^30 resulting in 4.566 seconds for C and 8.748 seconds for x86-64. 


![image](https://github.com/PatrickBro12244/LBYARCH/assets/135316690/0a564dce-b30d-4ca5-8383-ad27063feef7)


![image](https://github.com/PatrickBro12244/LBYARCH/assets/135316690/bdbc2e37-335d-4742-ae0b-c2fdbcb77ccc)


