
# importing the required module 
import matplotlib.pyplot as plt 

def main():
    # stores the file names of the results in the results folder
    resultsFiles = ["heap_sort", "quicksort", "merge_sort",
                    "radix_sort","counting_sort","bucket_sort", "insertion_sort"]
    xs = []
    ys = []

    # going through each result file
    for name in resultsFiles:
        try:
            resultsFile = open('results/{}.txt'.format(name), 'r')
            
            lines = resultsFile.readlines()
            count = 0
           
            # Strips the newline character
            for line in lines:
                count += 1

                words = line.split()
                #x and y values use to plot graph
                x = int(words[2])
                y = int(words[5])

                xs.append(x);
                ys.append(y);
                
            plotGraph(name, xs,ys)
           
            xs.clear();
            ys.clear();
        except IOError:
            print("\nFile {}.txt doesn't exists\n".format(name))
        finally:    
            resultsFile.close()
    
       
        

def plotGraph(name,xs, ys):
    print("\nCreating Graph for {}.".format(name))

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