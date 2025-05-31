using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabGUI4
{
    public enum Priority { Low, Medium, High }
    public enum Status { Pending, InProgress, Completed }

    public class Task
    {
        public string Name { get; set; }
        public Priority Priority { get; set; }
        public Status Status { get; set; }
        public DateTime StartDate { get; set; } 

        public Task(string name, Priority priority, Status status, int day, int month)
        {
            Name = name;
            Priority = priority;
            Status = status;
            StartDate = new DateTime(DateTime.Now.Year, month, day);
        }

        public virtual string GetDisplayInfo()
        {
            return $"{Name}, {Priority}, {Status}, {StartDate:dd.MM}";
        }
        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
