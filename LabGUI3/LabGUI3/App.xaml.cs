using System.Configuration;
using System.Data;
using System.Windows;

namespace DoorsCalculator
{
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

            var loginWindow = new LoginWindow();
            loginWindow.ShowDialog();
            if (loginWindow.DialogResult == true)
            {
                var mainWindow = new MainWindow();
                mainWindow.UserRole = loginWindow.UserRole;
                mainWindow.Show();
                loginWindow.Close();
            }
            else
            {
                Shutdown();
            }
        }
    }
}
