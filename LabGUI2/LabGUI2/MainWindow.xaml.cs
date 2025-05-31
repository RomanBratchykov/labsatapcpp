using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace LabGUI2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DispatcherTimer _timer;
        private int _secondsElapsed = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            _secondsElapsed++;
            TimeDisplay.Text = $"Time: {_secondsElapsed} s";
        }

        public void ShowMainMenu()
        {
            ContentArea.Visibility = Visibility.Collapsed;
            MainMenu.Visibility = Visibility.Visible;
        }

        private void SwitchTo(UserControl control)
        {
            ContentArea.Content = control;
            ContentArea.Visibility = Visibility.Visible;
            MainMenu.Visibility = Visibility.Collapsed;
        }

        private void Mass_Click(object sender, RoutedEventArgs e)
        {
            SwitchTo(new MassControl());
        }

        private void Len_Click(object sender, RoutedEventArgs e)
        {
            SwitchTo(new LenControl());
        }

        private void Area_Click(object sender, RoutedEventArgs e)
        {
            SwitchTo(new AreaControl());
        }

        private void Vol_Click(object sender, RoutedEventArgs e)
        {
            SwitchTo(new VolControl());
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }
    }
}