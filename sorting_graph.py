
# importing the required module 
import matplotlib.pyplot as plt 

def main():
    
    resultsFiles = ["heap_sort", "quicksort", "merge_sort",
                    "radix_sort","counting_sort","bucket_sort", "insertion_sort"]
    xs = []
    ys = []

    for name in resultsFiles:
        try:
            resultsFile = open('results/{}.txt'.format(name), 'r')
            
            lines = resultsFile.readlines()
            count = 0
            #print(name)
            # Strips the newline character
            for line in lines:
                count += 1

                words = line.split()
                x = int(words[2])
                y = int(words[5])

                #print("{})x= {} ,  y= {}".format(count, x,y));
                xs.append(x);
                ys.append(y);
                
            plotGraph(name, xs,ys)
           # print(xs)
            #print(ys)
            xs.clear();
            ys.clear();
        except IOError:
            print("\nFile {}.txt doesn't exists\n".format(name))
        finally:    
            resultsFile.close()
    
       
        

def plotGraph(name,xs, ys):
    print("Creating Graph for {}.".format(name))

    #print(xs)
    #print(ys)

    # plotting the points  
    plt.plot(xs, ys, '--bo') 
    
    # naming the x axis 
    plt.xlabel('x - axis') 
    # naming the y axis 
    plt.ylabel('y - axis') 
    
    # giving a title to my graph 
    plt.title('{} graph'.format(name)) 
    
    plt.grid()
    # function to show the plot 

    plt.savefig("graphs/{}.png".format(name))

    print("Graph for {} (png format) is located in the graph folder.".format(name))

    plt.cla()

main()