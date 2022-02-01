. f.sh 

# --------------------- MAIN CODE HERE --------------------- #
function menu()
#initiating menu function                  
{
    echo *******************
    echo
    echo A. Add data to your directory   
    echo B. Show all data      
    echo C. search directory 
    echo D. Edit data from your directory        
    echo E. remove data from your directory 
    echo      
    echo *******************

    read -p "Enter number of your choice(ex: A): "  choice

    if [ $choice = "A" ]; then
       addDir         
       #returning our add function               
    elif [ $choice = "B" ]; then
       dDirectory                      
       #'A-elif' returns our Directory function
    
    elif [ $choice = "C" ]; then
       checkDir                      
       # 'B-elif' returns our checkDir function

    elif [ $choice = "D" ]; then
       EditDir                      
       #'C-elif' returns our Edit function

    elif [ $choice = "E" ]; then
       rDirectory                    
       #'D-elif' returns our rDirectory function

    else
       echo "please check the menu again please"

    fi

}

menu     
#calling menu function
while :  
#endless loop
do
    
    read -p "Please press (y/Y) If you wish to continue and press (n/N) if you wish to end the program :  "  y  
    # alerting user to press Yes to continue or No to exit
    
    if [ $y = "Y" ] || [ $y = "y" ]; then      
    #checking and collecting when user press yes/Yes
       menu                                   
       #return menu function
    elif [ $y = "N" ] || [ $y = "n" ]; then    
    #checking and collecting when user press no/No
       exit 0                          
       #returning exit function
    else
       echo "Please choose (Y/N)"
    fi
done

