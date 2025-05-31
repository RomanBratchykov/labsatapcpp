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
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    public partial class MassControl : UserControl
    {
        public MassControl()
        {
            InitializeComponent();
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            if (Application.Current.MainWindow is MainWindow main)
            {
                main.ShowMainMenu();
            }
        }
        private void StartUnit_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Second.Items.Clear();
            SetValue.Clear();
            string? selected = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            if (selected == "Kilogram")
            {
                Second.Items.Add("Pound");
                Second.Items.Add("Ounce");
            }
            if (selected == "Pound")
            {
                Second.Items.Add("Ounce");
                Second.Items.Add("Kilogram");
            }
            if (selected == "Ounce")
            {
                Second.Items.Add("Pound");
                Second.Items.Add("Kilogram");
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
            else if (from == "Kilogram" && to == "Ounce")
            {
                SetValue.Text = (result * 32.15075).ToString();
            }
            else if (from == "Kilogram" && to == "Pound")
            {
                SetValue.Text = (result * 2.20462).ToString();
            }
            else if (from == "Ounce" && to == "Kilogram")
            {
                SetValue.Text = (result / 32.15075).ToString();
            }
            else if (from == "Ounce" && to == "Pound")
            {
                SetValue.Text = (result * 0.06857).ToString();
            }
            else if (from == "Pound" && to == "Kilogram")
            {
                SetValue.Text = (result / 2.20462).ToString();
            }
            else if (from == "Pound" && to == "Ounce")
            {
                SetValue.Text = (result / 0.06857).ToString();
            }
        }
      
        private void BackButton_Click(object sender, RoutedEventArgs e)
        {
            if (Application.Current.MainWindow is MainWindow main)
            {
                main.ShowMainMenu();
            }
        }
    }
}
