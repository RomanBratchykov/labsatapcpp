using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Navigation;
using System.Windows.Shapes;
using HomeworkGUI3.Properties;
namespace HomeworkGUI3
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public double getArea(float width, float height)
        {
            return width * height;
        }
        private void ConfirmButton_Click(object sender, RoutedEventArgs e)
        {

             float? Wwidth = float.Parse(WoodenWidthInput.Text);
             float? Wheight = float.Parse(WoodenHeightInput.Text);
             float? Wquantity = float.Parse(WoodenQuantityInput.Text);
             float? Wprice = Wwidth * Wheight * Wquantity * 35;
             float? MPwidth = float.Parse(MetalWidthInput.Text);
             float? MPheight = float.Parse(MetalHeightInput.Text);
             float? MPquantity = float.Parse(MetalQuantityInput.Text);
             float? MPprice = MPwidth * MPheight * MPquantity * 35;
            MessageBox.Show($"You have bought metal-plastic windows on {MPprice} $ and wooden windows on {Wprice} $");
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            var settingsWindow = new Settings();
            if (settingsWindow.ShowDialog() == true)
            {
                ApplySettings(settingsWindow.Settings);
                AppSettings.Save(settingsWindow.Settings);
            }
        }

        private void ExitButton_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        //private void ApplySettings(AppSettings settings)
        //{
        //    var brushConverter = new BrushConverter();
        //    TabControl.Background = (Brush)brushConverter.ConvertFrom(settings.BackgroundColor);
        //    this.Background = (Brush)brushConverter.ConvertFrom(settings.BackgroundColor);

        //    foreach (TabItem tab in TabControl.Items)
        //    {
        //        switch (settings.TabStyle.ToLower())
        //        {
        //            case "tabs":
        //                tab.FontWeight = FontWeights.Normal;
        //                tab.FontStyle = FontStyles.Normal;
        //                break;
        //            case "buttons":
        //                tab.FontWeight = FontWeights.Bold;
        //                tab.FontStyle = FontStyles.Normal;
        //                break;
        //            case "flat buttons":
        //                tab.FontWeight = FontWeights.Normal;
        //                tab.FontStyle = FontStyles.Italic;
        //                break;
        //        }
        //    }
        //}

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            Properties.Settings.Default.Save();
        }

    }
}