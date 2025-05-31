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
    /// Interaction logic for LenControl.xaml
    /// </summary>
    public partial class LenControl : UserControl
    {
        public LenControl()
        {
            InitializeComponent();
        }

        private void StartUnitLen_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SecondLen.Items.Clear();
            SetValueLen.Clear();
            string? selected = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            if (selected == "Kilometer")
            {
                SecondLen.Items.Add("Yard");
                SecondLen.Items.Add("Mile");
            }
            if (selected == "Yard")
            {
                SecondLen.Items.Add("Kilometer");
                SecondLen.Items.Add("Mile");
            }
            if (selected == "Mile")
            {
                SecondLen.Items.Add("Yard");
                SecondLen.Items.Add("Kilometer");
            }
        }

        private void GetRes_Click_1(object sender, RoutedEventArgs e)
        {
            SetValueLen.Clear();
            double? result = 0;
            string? from = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            string? to = SecondLen.SelectedItem?.ToString();
            string? value = GetValueLen.Text;
            if (value != string.Empty)
            {
                result = Convert.ToDouble(value);
            }
            if (value == string.Empty)
            {
                SetValueLen.Text = "Please enter a value.";
            }
            else if (from == "Kilometer" && to == "Mile")
            {
                SetValueLen.Text = (result * 0.62137).ToString();
            }
            else if (from == "Kilometer" && to == "Yard")
            {
                SetValueLen.Text = (result * 1093.6133).ToString();
            }
            else if (from == "Mile" && to == "Kilometer")
            {
                SetValueLen.Text = (result * 1.60934).ToString();
            }
            else if (from == "Mile" && to == "Yard")
            {
                SetValueLen.Text = (result * 1760).ToString();
            }
            else if (from == "Yard" && to == "Kilometer")
            {
                SetValueLen.Text = (result / 1093.6133).ToString();
            }
            else if (from == "Yard" && to == "Mile")
            {
                SetValueLen.Text = (result / 1760).ToString();
            }
        }
  

        private void BackButton_Click_1(object sender, RoutedEventArgs e)
        {
            if (Application.Current.MainWindow is MainWindow main)
            {
                main.ShowMainMenu();
            }
        }
    }
}
