bool isPrime(int number){
// or you can have it in here and this doesnt need to be in its own folder because its
// cross referenced in the folder
    for (int i = 2; i< number; i++){
        if (number%i==0){
            return false;
        }

    
    
    }
    return true;
}