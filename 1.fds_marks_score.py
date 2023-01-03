#1.  Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N  students in the class. Write functions to compute following: 
#a) The average score of class 
#b) Highest score and lowest score of class 
#c) Count of students who were absent for the test 
#d) Display mark with highest frequency

n=int(input("Enter the Number Of Students in the class:"))

this_list=[]
marks_list=[]

for i in range(n):
    marks=input("Enter the marks of Student or Mark 'A' if absent :")
    this_list.append(marks)

    if marks!='A':
        marks_list.append(int(marks))
    else:
        pass

def choice():
    print("Choose Among the following Options")
    print("1.Average Score Of Class")
    print("2.Highest and Lowest Score Of Class")
    print("3.Count of absent Students")
    print("4.Marks with Highest Frequency")
    print("5.Exit")

    ch=int(input("Enter your choice :"))

    if ch==1:
        avg()
        choice()

    if ch==2:
        highest_lowest()
        choice()

    elif ch==3:
        print("absent students are:",n-len(marks_list))
        choice()

    elif ch==4:
        count_marks(marks_list)
        choice()

def abs_count():

    for i in marks_list:
        if i=="A":
            abs_count+=1
        else:
            pass
        print("Number of absent Students are:",len(marks_list))


def avg():
    count=0
    sum=0
    for i in marks_list:
        sum=sum+i

    print("Average marks of Students is:",sum/len(marks_list))
    print("\n")

def highest_lowest():
    max=marks_list[0]
    min=marks_list[0]
    for i in marks_list:
        if i>max:
            max=i
        else:
            pass
    for j in marks_list:
        if j<min:
            min=j
        else:
            pass
    print("Highest Score is:",max)
    print("Lowest Score is:",min)


def count_marks(this_list):

    count_list=[]
    for i in this_list:
        count=0
        for j in this_list:
            if i==j:
                count+=1
        count_list.append(count)
            
    max_freq=0
    print(count_list)
    
    for i in count_list:
        if i>max_freq:
            max_freq=i

    index=0
    for i in range(len(count_list)):
        if count_list[i]==max_freq:
                    index=i
    print("Marks with max frequency is:",this_list[index])
                
choice()