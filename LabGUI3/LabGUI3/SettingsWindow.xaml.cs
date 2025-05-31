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
using System.Windows.Shapes;
using Microsoft.Win32;
namespace DoorsCalculator
{
    public partial class SettingsWindow : Window
    {
        public Dock SelectedTabPlacement { get; private set; }
        public Color SelectedBackgroundColor { get; private set; }
        public Color SelectedTabBackgroundColor { get; private set; }

        public SettingsWindow()
        {
            InitializeComponent();

            SelectedBackgroundColor = Colors.White;
            SelectedTabBackgroundColor = Colors.White;
            SelectedTabPlacement = Dock.Top;

            try
            {
                TabPlacementCombo.SelectedIndex = Properties.Settings.Default.TabPlacement;
                BackgroundColorPicker.SelectedColor = (Color)ColorConverter.ConvertFromString(Properties.Settings.Default.BackgroundColor);
                TabBackgroundColorPicker.SelectedColor = (Color)ColorConverter.ConvertFromString(Properties.Settings.Default.TabBackgroundColor);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка завантаження налаштувань: {ex.Message}", "Помилка", MessageBoxButton.OK, MessageBoxImage.Error);
                TabPlacementCombo.SelectedIndex = 0; 
                BackgroundColorPicker.SelectedColor = Colors.White;
                TabBackgroundColorPicker.SelectedColor = Colors.White;
            }
        }

        private void BackgroundColorPicker_SelectedColorChanged(object sender, RoutedPropertyChangedEventArgs<Color?> e)
        {
            if (BackgroundColorPicker.SelectedColor.HasValue)
            {
                SelectedBackgroundColor = BackgroundColorPicker.SelectedColor.Value;
            }
        }

        private void TabBackgroundColorPicker_SelectedColorChanged(object sender, RoutedPropertyChangedEventArgs<Color?> e)
        {
            if (TabBackgroundColorPicker.SelectedColor.HasValue)
            {
                SelectedTabBackgroundColor = TabBackgroundColorPicker.SelectedColor.Value;
            }
        }

        private void SaveButton_Click(object sender, RoutedEventArgs e)
        {
            SelectedTabPlacement = TabPlacementCombo.SelectedIndex switch
            {
                0 => Dock.Top,
                1 => Dock.Bottom,
                2 => Dock.Left,
                3 => Dock.Right,
                _ => Dock.Top
            };
            DialogResult = true;
        }
    }
}