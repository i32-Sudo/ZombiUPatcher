// Ignore this, This is developer issued code and has nothing to do with patching the game
// This code is for the older version of the Patcher (v1.3 and below) So ignore this.
//
// We updated it to (v1.4+) and now only has the modded game files and doesn't require any external code
// You can ignore this.


namespace ZombiU_XPatcherGUI
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new ZombiU_XPatcher());
        }
    }
}

