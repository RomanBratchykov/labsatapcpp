using System.Printing;
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

namespace HomeworkGUI
{

    public partial class MainWindow : Window
    {
        public double price = 0, priceDiscount = 0, priceNP = 0, priceC = 0;
        public MainWindow()
        {
            InitializeComponent();

        }

        private void Man_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Model.Items.Clear();
            string? selectedCategory = ((ComboBoxItem)Man.SelectedItem)?.Content.ToString();

        
            if (selectedCategory == "Lenovo")
            {
                Model.Items.Add("IdeaPad");
                Model.Items.Add("ThinkPad");
            }
            else if (selectedCategory == "Asus")
            {
                Model.Items.Add("Series X");
                Model.Items.Add("Series K");
            }
            else if (selectedCategory == "Dell")
            {
                Model.Items.Add("Inspirion");
                Model.Items.Add("Vostro");
            }
        }
        private void Model_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Series.Items.Clear();
            string? selectedCategory = Model.SelectedItem?.ToString();


            if (selectedCategory == "IdeaPad")
            {
                Series.Items.Add("3070");
                Series.Items.Add("3090");
            }
            else if (selectedCategory == "ThinkPad")
            {
                Series.Items.Add("A42");
                Series.Items.Add("A45");
            }
            else if (selectedCategory == "Series X")
            {
                Series.Items.Add("X50");
                Series.Items.Add("X51");
            }
            if (selectedCategory == "Series K")
            {
                Series.Items.Add("K80");
                Series.Items.Add("K82");
            }
            else if (selectedCategory == "Inspirion")
            {
                Series.Items.Add("XX30");
                Series.Items.Add("XZ30");
            }
            else if (selectedCategory == "Vostro")
            {
                Series.Items.Add("V01");
                Series.Items.Add("V03");
            }
        }
        private void Series_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Price.Clear();
            string? selectedCategory = Series.SelectedItem?.ToString();
            if (selectedCategory == "3070")
            {
                price = 56500;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "3090")
            {
                price = 41000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "X50")
            {
                price = 50000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "X51")
            {
                price = 42500;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "A42")
            {
                price = 37000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "A45")
            {
                price = 40000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "K80")
            {
                price = 21000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "K82")
            {
                price = 38000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "XX30")
            {
                price = 35200;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "XZ30")
            {
                price = 33500;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "V01")
            {
                price = 41000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }
            else if (selectedCategory == "V03")
            {
                price = 26000;
                Price.Text = price.ToString();
                FinalPrice.Text = price.ToString();
            }

        }
        private void Leave_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
        private void Clear_Click(object sender, RoutedEventArgs e)
        {
            Price.Clear();
            Man.SelectedItem = null;
            Model.ClearValue(ComboBox.SelectedValueProperty);
            Series.ClearValue(ComboBox.SelectedValueProperty);
            FinalPrice.Clear();
            dis1.IsChecked = false;
            dis2.IsChecked = false;
            dis10.IsChecked = false;
            dis20.IsChecked = false;
            FinalPrice.Clear();
            price = 0;
            priceDiscount = 0;
            priceNP = 0;
            priceC = 0;
        }

        private void Buy_Click(object sender, RoutedEventArgs e)
        { 
            if (FinalPrice.Text == string.Empty)
            {
               MessageBox.Show("You didn't choose final price");
            }
            else
            {
                MessageBox.Show("You have bought a " + Man.SelectionBoxItem.ToString() + " " + Model.SelectedItem?.ToString() + " "+ Series.SelectedItem?.ToString() + " with a price of " + FinalPrice.Text + " UAH.");
            }
        }

        private void dis10_Click(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            priceDiscount = price * 0.1;
            FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
        }

        private void dis20_Click(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            priceDiscount = price * 0.2;
            FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
        }

        private void dis1_Checked(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            priceNP = 200;
            FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
        }

        private void dis1_Unchecked(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            priceNP = 0;
            FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
        }

        private void dis2_Checked(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            else
            {
                priceC = 100;
                FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
            }
        }

        private void dis2_Unchecked(object sender, RoutedEventArgs e)
        {
            FinalPrice.Clear();
            if (Price.Text == string.Empty)
            {
                return;
            }
            priceC = 0;
            FinalPrice.Text = (price - priceDiscount + priceC + priceNP).ToString();
        }
    }
}
