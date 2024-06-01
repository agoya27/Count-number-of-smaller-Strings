P21.c -> Counts the number of instances of a smaller string pattern in a given text file. The name of the file is 
hardcoded into the program. The first method uses brute force approach to compute the results and prints the result
to screen once finished. It is observed that brute force approach takes around 15ms and 3 Million shifts to
complete the count

P22.c -> Counts the number of instances of a smaller string pattern in a given text file. The name of the file is 
hardcoded into the program. The first method uses Horspool's algorithm approach to compute the results and 
prints the result to screen once finished. It is observed that horspool algorithm approach takes around 40ms and 
500,00 shifts to complete the count when tested with string "maintain".

P23.c -> Counts the number of instances of a smaller string pattern in a given text file. The name of the file is 
hardcoded into the program. The first method uses boyre moore algorithm approach to compute the results and
prints the result to screen once finished. It is observed that boyre moore algorithm approach takes around 12ms 
and 450,00 shifts to complete the count when tested with string "maintain".


Analysis: 



Horspools's Algorithms: 
Word#		Word		   Time(ms)	      Shifts		Ratio (Time/shifts)

1) 		  the		          98		    1168930		 0.0000838
2)		  take		        84		     878347		 0.0000956
3)		  cello		        63		     719626		 0.0000875
4)		  strike	        57		     621563		 0.0000917
5)		  maintain        44		     502412		 0.0000875
6)		  calendar        46		     505801		 0.0000909
7) 		  University      41		     435827		 0.0000941
8)	    disclosure      38		     398511		 0.0000953
9)		  Statistics      39		     397198		 0.0000982
10)		 Confidentiality  28		     312642		 0.0000896

Avg of 10 Ratios using Horspool's Algorithm  =  0.0000914 


Boyre Moore Algorithms: 

Word#		Word		Time(ms)	  Shifts		  Ratio (Time/shifts)

1) 		the		          13		    1563972		     0.00000831 
2)		take		        10		    1053992		     0.00000949		 
3)		cello		        08		    797327 		     0.00001003		 
4)		strike		      09		    630862		     0.00001427		 
5)		maintain	      08		    449954		     0.00001778				 
6)		calendar	      09		    450482		     0.00001998				 
7) 		University	    09		    344477		     0.00002613		 
8)		disclosure	    11		    342682		     0.00003210 
9)		Statistics	    10		    345650		     0.00002893		 
10)		Confidentiality	 12		    216419		     0.00005545 

Avg of 10 Ratios using Boyre Moore Algorithm  =  0.00002225

Comparing the ratio's of the 2 algorithm, we can clearly conclude that Boyre Moore algorithm is better than Horpool algoritme 
for string searching since the avg ratio of time per unit shift is smaller for Boyer Moore algorithm.
