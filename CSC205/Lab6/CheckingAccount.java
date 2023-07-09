
public class CheckingAccount extends Account
{
        private int checks;
        
        public CheckingAccount(double initBalance, int checksWritten)
        {
                super(initBalance);
                checks = checksWritten;          
        }
        
        public void writeCheck(double amount)
        {
                withdraw(amount);
                checks++;
        }
        
        public int getChecksWritten()
        {
                return checks;
        }
        
}