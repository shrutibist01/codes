list_processes(){
    echo "List currently running processes: "
    ps
}

processes_info(){
    read -p "Enter the PID of the process: " pid
    echo "Information of process $pid"
    ps -p $pid
}

global_priority(){
    read -p "Enter the PID of the process: " pid
    echo "Global priority of $pid: " 
    ps -p $pid -o pid,pri
}

change_priority(){
    read -p "Enter the PID of the process: " pid
    read -p "Enter new priority (default: 10): " priority 
    priority=${priority:-10}
    renice $priority -p $pid
    echo "Priority of $pid changed to $priority"
}

while true; do
    echo "1. List processes"
    echo "2. Process info"
    echo "3. Global priority"
    echo "4. Change priority"
    echo "5. Exit"
    read -p "Choose an option: " choice
    case $choice in 
        1) list_processes ;;
        2) processes_info ;;
        3) global_priority ;;
        4) change_priority ;;
        5) echo "Exiting" ; exit ;;
        *) echo "Invalid option. Please choose again." ;;
    esac
done  
