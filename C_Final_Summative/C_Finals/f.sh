


#----------------------- OUR FUNCTIONS --------------------------------#


# FUNCTION -- remove record

function rDirectory(){
    #this function 'rDirectory' represent remove directory(data)
    read -p "checkDir by Surname: "  sankoh             
    #collecting user input

    if grep -E "$sankoh" record.txt; then           
    #this 'if' help us check if data exist
      read -p "Do you wish to rDirectory the data(Y/N): "  yn  
      #read and store user data
      if [ $yn = "Y" ] || [ $yn = "y" ]; then          
      #should user choose y or y
        sed -i "/$sankoh/d" record.txt                  
        # sed command helps us rDirectory data
        echo "Records remove successfully!"
      elif [ $yn = "N" ] || [ $yn = "n" ]; then       
      #when a user choose n or N
        echo "OK"
      else 
        echo "Please choose Y/N"           
        #when a user fail to choose either Y/N
      fi
    else
      echo "The given last first name is not in our directory"     
      #when a user enter a search name that's not in our database, this 'else' displace echo
    fi 


}

function dDirectory()             
#this function 'dDirectory' represent display directory (data)
{
   
   awk '{print $2, $3, $4 }' record.txt         
   # awk command Will display all records when executed
                                                                             
}




# FUNCTION -- add record


function addDir(){
    read -p "Enter a user first name: "  f_name                 
    #storing user input
    read -p "Enter a user last name: "  l_name            
    #storing user input
    read -p "Enter a user Phone number: "  phone          
    #storing user input
    read -p "Enter Email: "  email                 
    #storing user input

    echo "$l_name Names [$f_name$l_name]">>record.txt         
    #collecting and adding a user input to the record
    echo "$l_name Phone [+250] $phone">>record.txt            
    #collecting and adding a user to the record
    echo "$l_name Email [$email]">>record.txt                 
    #collecting and adding a user input to the record
    echo "#### ==============================================">>record.txt        
    #adding line to separate users record in the directory

    

}



# FUNCTION -- check  record

function checkDir(){

    read -p "search by Lastname: "  koh             
    #storing user input
    
    if grep "$koh" record.txt; then              
    #checking if searched name exit in directory
       echo "------------------------"

    else                                                    
    #in case search name does not exist in directory
      echo "The name you are looking for does not exist" 
    fi


}


# FUNCTION  -- Make Changes to record

function EditDir(){
    #make changes to directory
    read -p "check directory by Last name: "  sakoh                       
    #storing user input    

    if grep -E "$sakoh" record.txt; then                       
    #checking if searched name exit in directory
      read -p "Do you want to make changes to this record (Y/N): "  yn 

      if [ $yn = "Y" ] || [ $yn = "y" ]; then                   
      #If a user decide to choose y or y
         read -p "Enter new first name: "  f_name                     
         #storing new user input
         read -p "Enter new last name: "  l_name                 
         #storing new user input
         read -p "Enter new phone number: "  phone             
         #storing new user input
         read -p "Enter new email: "  email                     
         #storing new user input

         sed -i -e "s/.*$sakoh Names.*/$l_name Names [$f_name$l_name]/" record.txt      
         #this edit f_name with sed command
         sed -i -e "s/.*$sakoh Phone.*/$l_name Phone [+250] $phone/" record.txt         
         #this edit phone with sed command
         sed -i -e "s/.*$sakoh Email.*/$l_name Email [$email]/" record.txt              
         #this edit email with sed command
        
      
         echo "You have successfully edited your record!!"
      elif [ $yn = "N" ] || [ $yn = "n" ]; then                
      #should instead user choose n or N
         echo "OK"
      else 
         echo "Please choose Y/N"                             
         #extra case - user didn't choose either Y/N
      fi
    else
      echo "The search name you are looking for does not exist"             
      #when a user enter unavailable surname --- EXIT
    fi 


}


