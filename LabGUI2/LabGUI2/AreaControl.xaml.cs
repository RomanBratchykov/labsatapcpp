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
    /// Interaction logic for AreaControl.xaml
    /// </summary>
    public partial class AreaControl : UserControl
    {
        public AreaControl()
        {
            InitializeComponent();
        }

        private void StartUnit_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Second.Items.Clear();
            SetValue.Clear();
            string? selected = ((ComboBoxItem)StartUnit.SelectedItem)?.Content.ToString();
            if (selected == "Hectar")
            {
                Second.Items.Add("Acre");
                Second.Items.Add("Ar");
            }
            if (selected == "Acre")
            {
                Second.Items.Add("Hectar");
                Second.Items.Add("Ar");
            }
            if (selected == "Ar")
            {
                Second.Items.Add("Acre");
                Second.Items.Add("Hectar");
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
            else if (from == "Hectar" && to == "Acre")
            {
                SetValue.Text = (result * 2.471).ToString();
            }
            else if (from == "Hectar" && to == "Ar")
            {
                SetValue.Text = (result * 100).ToString();
            }
            else if (from == "Acre" && to == "Hectar")
            {
                SetValue.Text = (result / 2.47105).ToString();
            }
            else if (from == "Acre" && to == "Ar")
            {
                SetValue.Text = (result * 40.4685).ToString();
            }
            else if (from == "Ar" && to == "Hectar")
            {
                SetValue.Text = (result * 0.01).ToString();
            }
            else if (from == "Ar" && to == "Acre")
            {
                SetValue.Text = (result / 40.4685).ToString();
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
