using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LabGUI2
{
    /// <summary>
    /// Interaction logic for VolControl.xaml
    /// </summary>
    public partial class VolControl : UserControl
    {
        public VolControl()
        {
            InitializeComponent();
        }


        private void StartUnit_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Second.Items.Clear();
            SetValue.Clear();
            string? selected = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            if (selected == "Litre")
            {
                Second.Items.Add("Barrel");
                Second.Items.Add("Gallon");
            }
            if (selected == "Barrel")
            {
                Second.Items.Add("Litre");
                Second.Items.Add("Gallon");
            }
            if (selected == "Gallon")
            {
                Second.Items.Add("Litre");
                Second.Items.Add("Hectar");
            }
        }

        private void BackButton_Click(object sender, RoutedEventArgs e)
        {
            if (Application.Current.MainWindow is MainWindow main)
            {
                main.ShowMainMenu();
            }
        }

        private void GetRes_Click(object sender, RoutedEventArgs e)
        {
            SetValue.Clear();
            double? result = 0;
            string? from = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            string? to = Second.SelectedItem?.ToString();
            string? value = GetValue.Text;
            if (value != string.Empty)
            {
                result = Convert.ToDouble(value);
            }
            if (value == string.Empty)
            {
                SetValue.Text = "Please enter a value.";
            }
            else if (from == "Litre" && to == "Barrel")
            {
                SetValue.Text = (result * 163.65).ToString();
            }
            else if (from == "Litre" && to == "Gallon")
            {
                SetValue.Text = (result * 4.5461).ToString();
            }
            else if (from == "Barrel" && to == "Litre")
            {
                SetValue.Text = (result / 163.65).ToString();
            }
            else if (from == "Barrel" && to == "Gallon")
            {
                SetValue.Text = (result * 0.00611).ToString();
            }
            else if (from == "Gallon" && to == "Litre")
            {
                SetValue.Text = (result / 4.5461).ToString();
            }
            else if (from == "Gallon" && to == "Barrel")
            {
                SetValue.Text = (result / 0.00611).ToString();
            }
        }
    }
}
