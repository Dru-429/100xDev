const puppeteer = require('puppeteer');

(async () => {
  // Launch browser in non-headless mode so you can watch it click (set headless: true if you want it in background)
  const browser = await puppeteer.launch({
    headless: false,
    defaultViewport: null
  });

  const page = await browser.newPage();

  console.log('Navigating to topclick.app...');
  await page.goto('https://www.topclick.app/', { waitUntil: 'networkidle2' });

  // Selector for the button based on aria-label
  const buttonSelector = 'button[aria-label="Click for Github wrapped"]';

  // Wait until the button is visible on the page
  await page.waitForSelector(buttonSelector);

  console.log('Button found. Starting 500 clicks...');

  // Get handle for the button
  const button = await page.$(buttonSelector);

  if (button) {
    const totalClicks = 500;
    for (let i = 1; i <= totalClicks; i++) {
      await button.click();
      
      // Optional small delay (5ms) between clicks to prevent frame dropping or UI freezing
      await new Promise(resolve => setTimeout(resolve, 5));

      if (i % 50 === 0 || i === totalClicks) {
        console.log(`Clicked ${i}/${totalClicks} times`);
      }
    }
    console.log('Finished clicking 500 times!');
  } else {
    console.error('Button not found!');
  }

  // Keep browser open briefly before closing
  await new Promise(resolve => setTimeout(resolve, 2000));
  await browser.close();
})();