using System.Data;
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

namespace DoorsCalculator
{
    public partial class MainWindow : Window
    {
        private string? userRole;
        private string? interiorDoorImageSource = "metal_interior.jpg";
        private string? entranceDoorImageSource = "metal_entrance.jpg";

        public MainWindow()
        {
            try
            {
                InitializeComponent();

                DiscountCombo.Visibility = Visibility.Collapsed;
                DeliveryCombo.Visibility = Visibility.Collapsed;

                TabControl.TabStripPlacement = (Dock)Properties.Settings.Default.TabPlacement;
                Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString(Properties.Settings.Default.BackgroundColor));
                TabControl.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString(Properties.Settings.Default.TabBackgroundColor));

                UpdateImageSources();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка ініціалізації MainWindow: {ex.Message}", "Помилка", MessageBoxButton.OK, MessageBoxImage.Error);
                this.Close();
            }
        }

        public string UserRole
        {
            get => userRole;
            set
            {
                userRole = value;
                DiscountCombo.Visibility = userRole == "Master" ? Visibility.Visible : Visibility.Collapsed;
                DeliveryCombo.Visibility = userRole == "Client" ? Visibility.Visible : Visibility.Collapsed;
            }
        }

        private void Material_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            UpdateImageSources();
        }

        private void UpdateImageSources()
        {
            try
            {
                interiorDoorImageSource = InteriorMaterial.SelectedItem is ComboBoxItem interiorItem && interiorItem.Content.ToString() == "Дерево" ? "wooden_interior.jpg" : "metal_interior.jpg";
                entranceDoorImageSource = EntranceMaterial.SelectedItem is ComboBoxItem entranceItem && entranceItem.Content.ToString() == "Дерево" ? "wooden_entrance.jpg" : "metal_entrance.jpg";
                InteriorDoorImage.Source = new System.Windows.Media.Imaging.BitmapImage(new System.Uri($"D:\\cpp\\labsatapcpp\\LabGUI3\\LabGUI3\\Images\\{interiorDoorImageSource}", UriKind.Absolute));
                EntranceDoorImage.Source = new System.Windows.Media.Imaging.BitmapImage(new System.Uri($"D:\\cpp\\labsatapcpp\\LabGUI3\\LabGUI3\\Images\\{entranceDoorImageSource}", UriKind.Absolute));
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка завантаження зображень: {ex.Message}", "Помилка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private void CalculateButton_Click(object sender, RoutedEventArgs e)
        {
            double totalCost = 0;
            string calculationDetails = "Розрахунок вартості:\n";

            if (TabControl.SelectedIndex == 0 && double.TryParse(InteriorWidth.Text, out double iWidth) && double.TryParse(InteriorHeight.Text, out double iHeight) && int.TryParse(InteriorQuantity.Text, out int iQuantity))
            {
                double area = iWidth * iHeight;
                double materialCost = (InteriorMaterial.SelectedItem as ComboBoxItem).Content.ToString() == "Метал" ? 400 : 500;
                double fittingsCost = (InteriorFittings.SelectedItem as ComboBoxItem).Content.ToString() == "BLUM" ? 90 : 60;
                totalCost += (area * materialCost + fittingsCost) * iQuantity;
                calculationDetails += $"Міжкімнатні двері: {iQuantity} шт, {area:F2} м², Матеріал: {(InteriorMaterial.SelectedItem as ComboBoxItem).Content}, Фурнітура: {(InteriorFittings.SelectedItem as ComboBoxItem).Content}\n";

                if (InteriorDismantle.IsChecked == true)
                {
                    totalCost += 20 * iQuantity;
                    calculationDetails += "Демонтаж: $20\n";
                }
                if (InteriorInstall.IsChecked == true)
                {
                    totalCost += 50 * iQuantity;
                    calculationDetails += "Встановлення: $50\n";
                }
            }

            if (TabControl.SelectedIndex == 1 && double.TryParse(EntranceWidth.Text, out double eWidth) && double.TryParse(EntranceHeight.Text, out double eHeight) && int.TryParse(EntranceQuantity.Text, out int eQuantity))
            {
                double area = eWidth * eHeight;
                double materialCost = (EntranceMaterial.SelectedItem as ComboBoxItem).Content.ToString() == "Метал" ? 400 : 500;
                double fittingsCost = (EntranceFittings.SelectedItem as ComboBoxItem).Content.ToString() == "BLUM" ? 90 : 60;
                totalCost += (area * materialCost + fittingsCost) * eQuantity;
                calculationDetails += $"Вхідні двері: {eQuantity} шт, {area:F2} м², Матеріал: {(EntranceMaterial.SelectedItem as ComboBoxItem).Content}, Фурнітура: {(EntranceFittings.SelectedItem as ComboBoxItem).Content}\n";

                if (EntranceDismantle.IsChecked == true)
                {
                    totalCost += 20 * eQuantity;
                    calculationDetails += "Демонтаж: $20\n";
                }
                if (EntranceInstall.IsChecked == true)
                {
                    totalCost += 50 * eQuantity;
                    calculationDetails += "Встановлення: $50\n";
                }
            }

            if (userRole == "Master" && DiscountCombo.SelectedItem is ComboBoxItem discountItem)
            {
                if (discountItem.Content.ToString() == "5%")
                {
                    totalCost *= 0.95;
                    calculationDetails += "Знижка: 5%\n";
                }
                else if (discountItem.Content.ToString() == "10%")
                {
                    totalCost *= 0.90;
                    calculationDetails += "Знижка: 10%\n";
                }
            }

            if (userRole == "Client" && DeliveryCombo.SelectedItem is ComboBoxItem deliveryItem && (TabControl.SelectedIndex == 0 || TabControl.SelectedIndex == 1))
            {
                double area = TabControl.SelectedIndex == 0 ? double.Parse(InteriorWidth.Text) * double.Parse(InteriorHeight.Text) : double.Parse(EntranceWidth.Text) * double.Parse(EntranceHeight.Text);
                if (deliveryItem.Content.ToString() == "Платна доставка")
                {
                    totalCost += area * 10;
                    calculationDetails += $"Платна доставка: ${area * 10:F2}\n";
                }
                else if (deliveryItem.Content.ToString() == "Безкоштовна доставка")
                {
                    calculationDetails += "Безкоштовна доставка\n";
                }
            }

            calculationDetails += $"Загальна вартість: ${totalCost:F2}";
            MessageBox.Show(calculationDetails, "Розрахунок", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            var settingsWindow = new SettingsWindow();
            if (settingsWindow.ShowDialog() == true)
            {
                TabControl.TabStripPlacement = settingsWindow.SelectedTabPlacement;
                Background = new SolidColorBrush(settingsWindow.SelectedBackgroundColor);
                TabControl.Background = new SolidColorBrush(settingsWindow.SelectedTabBackgroundColor);

                Properties.Settings.Default.TabPlacement = (int)settingsWindow.SelectedTabPlacement;
                Properties.Settings.Default.BackgroundColor = settingsWindow.SelectedBackgroundColor.ToString();
                Properties.Settings.Default.TabBackgroundColor = settingsWindow.SelectedTabBackgroundColor.ToString();
                Properties.Settings.Default.Save();
            }
        }
    }
}